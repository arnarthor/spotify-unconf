open Css;
[@bs.deriving {jsConverter: newType}]
type food = {
  food: string,
  beverages: array(string),
};

[@bs.module] external meetupFood: unit => abs_food = "./meetupFood.js";

[@bs.deriving {jsConverter: newType}]
type info = {
  date: string,
  time: string,
  location: string,
};

[@bs.module "./MeetupInformation.js"]
external meetupInfo: unit => abs_info = "default";

type state = {attendees: int};
type action =
  | AddAttendee
  | SubtractAttendee;

let component = ReasonReact.reducerComponent(__MODULE__);

[@bs.deriving jsConverter]
type speaker = {
  name: string,
  talk: string,
  image: string,
};

type speakersList = list(speaker);

let make = (speakers, _children) => {
  let renderSpeaker = ({name, talk, image}) =>
    <div
      className={
        style([
          display(`flex),
          alignItems(`center),
          justifyContent(`center),
          flexDirection(`column),
          padding(px(20)),
          margin(px(20)),
          backgroundColor(hex("dadada")),
          borderRadius(px(10)),
          width(px(400)),
        ])
      }>
      <div className={style([margin(px(5))])}>
        {ReasonReact.string("Name: ")}
        <strong> {ReasonReact.string(name)} </strong>
      </div>
      <div className={style([margin(px(5))])}>
        {ReasonReact.string("Talk: ")}
        <strong> {ReasonReact.string(talk)} </strong>
      </div>
      <div className={style([margin(px(5))])}> <Img image /> </div>
    </div>;
  {
    ...component,
    initialState: () => {attendees: 0},
    reducer: (action, state) =>
      switch (action) {
      | AddAttendee => ReasonReact.Update({attendees: state.attendees + 1})
      | SubtractAttendee =>
        ReasonReact.Update({attendees: state.attendees - 1})
      },
    render: ({state, send}) => {
      let {date, time, location} = infoFromJs(meetupInfo());
      let {food, beverages} = foodFromJs(meetupFood());
      <div
        className={
          style([
            display(`flex),
            alignItems(`center),
            justifyContent(`center),
            flexDirection(`column),
          ])
        }>
        <div className={style([margin(px(5))])}>
          <button
            className={style([padding(px(8)), margin(px(5))])}
            onClick={_event => send(SubtractAttendee)}>
            {ReasonReact.string("-")}
          </button>
          {ReasonReact.string("Attendees: ")}
          <strong>
            {ReasonReact.string(string_of_int(state.attendees))}
          </strong>
          <button
            className={style([padding(px(8)), margin(px(5))])}
            onClick={_event => send(AddAttendee)}>
            {ReasonReact.string("+")}
          </button>
        </div>
        <div>
          <div className={style([margin(px(5))])}>
            {ReasonReact.string("Date: ")}
            <strong> {ReasonReact.string(date)} </strong>
          </div>
          <div className={style([margin(px(5))])}>
            {ReasonReact.string("Time: ")}
            <strong> {ReasonReact.string(time)} </strong>
          </div>
          <div className={style([margin(px(5))])}>
            {ReasonReact.string("Location: ")}
            <strong> {ReasonReact.string(location)} </strong>
          </div>
          <div className={style([margin(px(5))])}>
            {ReasonReact.string("Food: ")}
            <strong> {ReasonReact.string(food)} </strong>
          </div>
          <div className={style([margin(px(5))])}>
            {ReasonReact.string("Beverages: ")}
            <strong>
              {ReasonReact.string(beverages |> Js.Array.joinWith(", "))}
            </strong>
          </div>
        </div>
        {
          Belt.List.map(speakers, renderSpeaker)
          |> Belt.List.toArray
          |> ReasonReact.array
        }
      </div>;
    },
  };
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    jsProps => {
      let speakers =
        jsProps##speakers |> Array.to_list |> List.map(speakerFromJs);
      make(speakers, [||]);
    },
  );
