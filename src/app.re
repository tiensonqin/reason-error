[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type state = { id: int };

type action =
  | Increment;

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => {id: 0},
  reducer: (_, state) =>
    ReasonReact.Update(()),
  render: (self) =>
    <div className="App">
      <p> (ReasonReact.stringToElement(string_of_int(self.state.id))) </p>
      <a onClick=(self.reduce((_event) => Increment))>(ReasonReact.stringToElement("Increment"))</a>
    </div>
};
