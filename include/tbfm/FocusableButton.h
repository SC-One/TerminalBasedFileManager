//#ifndef FOCUSABLEBUTTON_H
//#define FOCUSABLEBUTTON_H

//#include <ftxui/component/component.hpp>
//#include <ftxui/component/component_base.hpp>
//#include <ftxui/component/event.hpp>
//#include <ftxui/component/screen_interactive.hpp>  // for ScreenInteractive
//#include <ftxui/dom/elements.hpp>

// namespace CC {
// using namespace ftxui;
//// NOLINTNEXTLINE(readability-function-cognitive-complexity)
// Component Button(ConstStringRef label, std::function<void()> on_click,
//                  Ref<ButtonOption> option) {
//   class Impl : public ComponentBase {
//    public:
//     Impl(ConstStringRef label, std::function<void()> on_click,
//          Ref<ButtonOption> option)
//         : label_(std::move(label)),
//           on_click_(std::move(on_click)),
//           option_(std::move(option)) {}

//    // Component implementation:
//    Element Render() override {
//      const bool active = Active();
//      const bool focused = Focused();
//      const bool focused_or_hover = focused || mouse_hover_;

//      float target = focused_or_hover ? 1.F : 0.F;  // NOLINT
//      if (target != animator_background_.to()) {
//        SetAnimationTarget(target);
//      }

//      auto focus_management = focused ? focus : active ? select : nothing;
//      const EntryState state = {
//          *label_,
//          false,
//          active,
//          focused_or_hover,
//      };

//      auto element =
//          (option_->transform ? option_->transform : DefaultTransform)  //
//          (state);
//      return element | AnimatedColorStyle() | focus_management |
//      reflect(box_);
//    }

//    Decorator AnimatedColorStyle() {
//      Decorator style = nothing;
//      if (option_->animated_colors.background.enabled) {
//        style = style | bgcolor(Color::Interpolate(
//                            animation_foreground_,  //
//                            option_->animated_colors.background.inactive,
//                            option_->animated_colors.background.active));
//      }
//      if (option_->animated_colors.foreground.enabled) {
//        style = style | color(Color::Interpolate(
//                            animation_foreground_,  //
//                            option_->animated_colors.foreground.inactive,
//                            option_->animated_colors.foreground.active));
//      }
//      return style;
//    }

//    void SetAnimationTarget(float target) {
//      if (option_->animated_colors.foreground.enabled) {
//        animator_foreground_ =
//            animation::Animator(&animation_foreground_, target,
//                                option_->animated_colors.foreground.duration,
//                                option_->animated_colors.foreground.function);
//      }
//      if (option_->animated_colors.background.enabled) {
//        animator_background_ =
//            animation::Animator(&animation_background_, target,
//                                option_->animated_colors.background.duration,
//                                option_->animated_colors.background.function);
//      }
//    }

//    void OnAnimation(animation::Params& p) override {
//      animator_background_.OnAnimation(p);
//      animator_foreground_.OnAnimation(p);
//    }

//    void OnClick() {
//      on_click_();
//      animation_background_ = 0.5F;  // NOLINT
//      animation_foreground_ = 0.5F;  // NOLINT
//      SetAnimationTarget(1.F);       // NOLINT
//    }

//    bool OnEvent(Event event) override {
//      if (event.is_mouse()) {
//        return OnMouseEvent(event);
//      }

//      if (event == Event::Return) {
//        OnClick();
//        return true;
//      }
//      return false;
//    }

//    bool OnMouseEvent(Event event) {
//      mouse_hover_ =
//          box_.Contain(event.mouse().x, event.mouse().y) &&
//          CaptureMouse(event);

//      if (!mouse_hover_) {
//        return false;
//      }

//      if (event.mouse().button == Mouse::Left &&
//          event.mouse().motion == Mouse::Pressed) {
//        TakeFocus();
//        OnClick();
//        return true;
//      }

//      return false;
//    }

//    bool Focusable() const final { return true; }

//   private:
//    ConstStringRef label_;
//    std::function<void()> on_click_;
//    bool mouse_hover_ = false;
//    Box box_;
//    Ref<ButtonOption> option_;
//    float animation_background_ = 0;
//    float animation_foreground_ = 0;
//    animation::Animator animator_background_ =
//        animation::Animator(&animation_background_);
//    animation::Animator animator_foreground_ =
//        animation::Animator(&animation_foreground_);
//  };

//  return Make<Impl>(std::move(label), std::move(on_click), std::move(option));
//}

//}  // namespace CC
//#endif  // FOCUSABLEBUTTON_H
