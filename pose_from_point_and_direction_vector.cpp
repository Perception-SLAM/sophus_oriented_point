#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry> 
#include <sophus/so3.hpp>
#include <sophus/se3.hpp>

int main(int arg_count, char ** arg_array)
{
  const Eigen::Vector3f translation_vector(1,2,3);
  const Eigen::Vector3f direction_vector(0,1,1);
  //Chose the correct forward vector for your coordinate frame.
  const Eigen::Vector3f forward_vector(1,0,0);
  const Eigen::Quaternion<float> orientation =
    Eigen::Quaternion<float>::FromTwoVectors(forward_vector,direction_vector);
  const Sophus::SO3<float> so3_object = Sophus::SO3<float>(orientation);
  const Sophus::SE3<float> se3_object = Sophus::SE3<float>(orientation,
      translation_vector);

  std::cout << "Translation vector: " << se3_object.translation().transpose()
    << std::endl;
  std::cout << "Rotation matrix: "
    << se3_object.rotationMatrix().eulerAngles(0,1,2).transpose()*180/M_PI
    << std::endl;
  return 0;
}
