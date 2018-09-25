module ImgJs = {
  [@bs.module "./image.js"]
  external reactClass: ReasonReact.reactClass = "imageComponent";

  let make = (~imageSrc, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"imageSrc": imageSrc},
      children,
    );
};

open Css;

let component = ReasonReact.statelessComponent(__MODULE__);

let make = (~imageSrc, _children) => {
  ...component,
  render: _ =>
    <div className={style([height(px(300)), width(px(300))])}>
      <ImgJs imageSrc />
    </div>,
};
