/* NodeEvents.re */

/* A collection of event handlers to be used by the Nodes */

open Revery_Core;

type mouseMoveEventParams = {
  mouseX: float,
  mouseY: float,
};

type mouseButtonEventParams = {
  mouseX: float,
  mouseY: float,
  button: MouseButton.t,
};

type mouseWheelEventParams = {
  deltaX: float,
  deltaY: float,
};

/*
  Might be useful to extend in the future
 */
type focusEventParams = unit;

type keyEventParams = {
  key: Key.t,
  scancode: int,
  altKey: bool,
  ctrlKey: bool,
  shiftKey: bool,
  superKey: bool,
  isRepeat: bool,
}

type keyPressEventParams = {
  codepoint: int,
  character: string,
}

type event =
  | MouseDown(mouseButtonEventParams)
  | MouseMove(mouseMoveEventParams)
  | MouseUp(mouseButtonEventParams)
  | MouseWheel(mouseWheelEventParams)
  | KeyDown(keyEventParams)
  | KeyUp(keyEventParams)
  | KeyPress(keyPressEventParams)
  | Blur
  | Focus;

type refCallback('a) = 'a => unit;
type mouseButtonHandler = mouseButtonEventParams => unit;
type mouseMoveHandler = mouseMoveEventParams => unit;
type mouseWheelHandler = mouseWheelEventParams => unit;
type focusHandler = focusEventParams => unit;
type keyDownHandler = keyEventParams => unit;
type keyUpHandler = keyEventParams => unit;
type keyPressHandler = keyPressEventParams => unit;

type t('a) = {
  ref: option(refCallback('a)),
  onMouseDown: option(mouseButtonHandler),
  onMouseMove: option(mouseMoveHandler),
  onMouseUp: option(mouseButtonHandler),
  onMouseWheel: option(mouseWheelHandler),
  onFocus: option(focusHandler),
  onBlur: option(focusHandler),
  onKeyUp: option(keyUpHandler),
  onKeyDown: option(keyDownHandler),
  onKeyPress: option(keyPressHandler),
};

let make =
    (
      ~ref=?,
      ~onMouseDown=?,
      ~onMouseMove=?,
      ~onMouseUp=?,
      ~onMouseWheel=?,
      ~onFocus=?,
      ~onBlur=?,
      ~onKeyPress=?,
      ~onKeyDown=?,
      ~onKeyUp=?,
      _unit: unit,
    ) => {
  let ret: t('a) = {
    ref,
    onMouseDown,
    onMouseMove,
    onMouseUp,
    onMouseWheel,
    onFocus,
    onBlur,
    onKeyPress,
    onKeyDown,
    onKeyUp
  };
  ret;
};
