// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");
var ImgJs = require("./img.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function make(image, children) {
  return ReasonReact.wrapJsForReason(ImgJs.imageComponent, {
              image: image
            }, children);
}

var ImgJs$1 = /* module */[/* make */make];

var component = ReasonReact.statelessComponent("Img");

function make$1(image, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          className: Css.style(/* :: */[
                                Css.height(Css.px(300)),
                                /* :: */[
                                  Css.width(Css.px(300)),
                                  /* [] */0
                                ]
                              ])
                        }, ReasonReact.element(undefined, undefined, make(image, /* array */[])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.ImgJs = ImgJs$1;
exports.component = component;
exports.make = make$1;
/* component Not a pure module */