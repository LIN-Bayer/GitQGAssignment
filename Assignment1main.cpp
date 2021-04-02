#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    //定义一个旋转矩阵
    Eigen::Matrix4f rotation;
    //绕z轴旋转的变换矩阵
    rotation << cos(rotation_angle/180*acos(-1)), -sin(rotation_angle / 180 * acos(-1)), 0, 0,
                sin(rotation_angle), cos(rotation_angle), 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 1;
    //让矩阵做绕z轴的旋转变换
    model = rotation * model;

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    //定义一个透视投影转正交投影的矩阵
    Eigen::Matrix4f Perspective;
    Perspective << zNear, 0, 0, 0,
                   0, zNear, 0, 0,
                   0, 0, zNear + zFar, -zNear * zFar,
                   0, 0, 1, 0;
    //y轴top
    float t = zNear * tan(eye_fov / 2 / 180 * acos(-1));
    //y轴bottom
    float b = -t;
    //x轴right
    float r = t / aspect_ratio;
    //x轴left 
    float l = -r;

    //定义两个正交投影矩阵
    Eigen::Matrix4f Ortho1, Ortho2;
    Ortho1 << 1, 0, 0, -(r + l) / 2,
              0, 1, 0, -(t + b) / 2,
              0, 0, 1, -(zNear + zFar) / 2,
              0, 0, 0, 1;
    Ortho2 << 2 / (r - l), 0, 0, 0,
              0, 2 / (t - b), 0, 0,
              0, 0, 2 / (zNear - zFar), 0,
              0, 0, 0, 1;

    //透视投影
    projection = Ortho2 * Ortho1 * Perspective;
    return projection;
}

////绕任意轴旋转
//Eigen::Matrix4f get_rotation(Vector3f axis,float angle)
//{
//    //定义绕任意轴旋转的变换矩阵
//    Eigen::Matrix4f rotation = Eigen::Matrix4f::Identity();
//    //旋转轴axis的坐标表示为（x,y,z）
//    /*Eigen::Vector3f n;*/
//    float x, y, z;
//    /*n << x, y, z;
//    n = axis;*/
//    x = axis.x();
//    y = axis.y();
//    z = axis.z();
//    rotation << x * x * (1 - cos(angle / 180 * acos(-1))) + cos(angle / 180 * acos(-1)), x* y* (1 - cos(angle / 180 * acos(-1))) + z * sin(angle / 180 * acos(-1)), x* z* (1 - cos(angle / 180 * acos(-1))) - z * sin(angle / 180 * acos(-1)),0,
//        x* y* (1 - cos(angle / 180 * acos(-1))) - z * sin(angle / 180 * acos(-1)), y* y* (1 - cos(angle / 180 * acos(-1))) + cos(angle / 180 * acos(-1)), y* z* (1 - cos(angle / 180 * acos(-1))) + x * sin(angle / 180 * acos(-1)),0,
//        x* z* (1 - cos(angle / 180 * acos(-1))) + y * sin(angle / 180 * acos(-1)), y* z* (1 - cos(angle / 180 * acos(-1))) - z * sin(angle / 180 * acos(-1)), z* z* (1 - cos(angle / 180 * acos(-1))) + cos(angle / 180 * acos(-1)),0,
//        0, 0, 0, 1;
//
//    return rotation;
//}





int main(int argc, const char** argv)
{
    float angle = 0;
    Vector3f axis;
    axis << 1, 1, 1;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        /*r.set_model(get_rotation(axis,angle));*/
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        /*r.set_model(get_rotation(axis,angle));*/  //绕任意轴
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
