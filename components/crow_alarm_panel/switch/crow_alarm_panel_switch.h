#pragma once

#include "esphome/core/component.h"
#include "esphome/components/crow_alarm_panel/crow_alarm_panel.h"
#include "esphome/components/switch/switch.h"

namespace esphome {
namespace crow_alarm_panel {

class CrowAlarmPanelSwitch : public switch_::Switch, public Component {
 public:
  void dump_config() override;

  void set_crow_alarm_panel_parent(CrowAlarmPanel *parent) { this->parent_ = parent; }

 protected:
  virtual void write_state(bool state) = 0;

  CrowAlarmPanel *parent_;
};

class CrowAlarmPanelOutputSwitch : public CrowAlarmPanelSwitch {
 public:
  void set_output_number(uint8_t output_number) { this->output_number_ = output_number; }
  void dump_config() override;
 protected:
  void write_state(bool state) override;

  uint8_t output_number_;
};

}  // namespace crow_alarm_panel
}  // namespace esphome
