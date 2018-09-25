module ImgJs = {
  [@bs.module "./img.js"]
  external reactClass: ReasonReact.reactClass = "imageComponent";

  let make = (~image, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"image": image},
      children,
    );
};

open Css;

let component = ReasonReact.statelessComponent(__MODULE__);

let make = (~image, _children) => {
  ...component,
  render: _ =>
    <div className={style([height(px(300)), width(px(300))])}>
      <ImgJs image />
    </div>,
};
