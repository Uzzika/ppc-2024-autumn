#pragma once

#include <memory>
#include <vector>

#include "core/task/include/task.hpp"
#include "seq/chernykh_a_adjust_image_contrast/include/pixel.hpp"

namespace chernykh_a_adjust_image_contrast_seq {

class SequentialTask : public ppc::core::Task {
 public:
  explicit SequentialTask(std::shared_ptr<ppc::core::TaskData> task_data, float contrast_factor)
      : Task(std::move(task_data)), contrast_factor(contrast_factor) {}
  bool validation() override;
  bool pre_processing() override;
  bool run() override;
  bool post_processing() override;

 private:
  float contrast_factor{};
  std::vector<Pixel> input, result;
};

}  // namespace chernykh_a_adjust_image_contrast_seq