#pragma once

#include <Eigen/Dense>

#include "drake/common/drake_deprecated.h"
#include "drake/math/rigid_transform.h"
#include "drake/systems/framework/basic_vector.h"

namespace drake {
namespace systems {
namespace rendering {

/// A 7-vector representing the transform of frame A in the world frame, X_WA,
/// in the form `{p_WA, R_WA}`, where `p` is represented as an x-y-z
/// translation, and `R` is represented as a quaternion. The exact order of
/// elements is `{x, y, z, qw, qx, qy, qz}`.
///
/// @tparam_default_scalar
template <typename T>
class DRAKE_DEPRECATED("2021-12-01",
                       "PoseVector is no longer in use. Visualizers typically "
                       "connect to SceneGraph's QueryObject port.")
PoseVector : public BasicVector<T> {
 public:
  /// Default constructor.
  PoseVector();
  ~PoseVector() override;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  /// Fully-parameterized constructor.
  /// @param rotation the orientation R_WA of frame A in the world frame W.
  /// @param translation the position vector p_WA giving A's origin measured
  /// from W's origin, expressed in W.
  PoseVector(const Eigen::Quaternion<T>& rotation,
             const Eigen::Translation<T, 3>& translation);
#pragma GCC diagnostic pop

  /// Returns the transform X_WA.
  math::RigidTransform<T> get_transform() const;
  /// Assigns the transform X_WA.
  void set_transform(const math::RigidTransform<T>& transform);

  /// Returns the translation p_WA.
  Eigen::Translation<T, 3> get_translation() const;
  /// Assigns the translation p_WA.
  void set_translation(const Eigen::Translation<T, 3>& q);

  /// Returns the rotation R_WA.
  Eigen::Quaternion<T> get_rotation() const;
  /// Assigns the rotation R_WA.
  void set_rotation(const Eigen::Quaternion<T>& q);

  static constexpr int kSize = 7;

 protected:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  [[nodiscard]] PoseVector<T>* DoClone() const override;
#pragma GCC diagnostic pop
};

}  // namespace rendering
}  // namespace systems
}  // namespace drake
