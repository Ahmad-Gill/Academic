import React, { useState, useEffect, useRef } from "react";

function HookForm() {
  // useState: Stores the input value
  const [name, setName] = useState("");

  // useRef: Creates a reference to the input field
  const inputRef = useRef(null);

  // useEffect #1: Focus the input field when the component mounts
  useEffect(() => {
    inputRef.current.focus(); //doesnot set focus ech time the page rerenders but only when the page mounts
  }, []); // Runs only once when the component mounts

  // useEffect #2: Runs whenever `name` changes
  useEffect(() => {
    console.log("Name changed useRef:", inputRef.current.value);
    console.log("Name changed useState:", name);
  }, [name]); // Runs when `name` updates
  // inputRef also have the text field becuse it is bind to text field using ref, hence inputRef.current.value is same as name

  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      {/* Input field using useRef */}
      <input
        ref={inputRef}
        type="text"
        placeholder="Enter your name..."
        value={name}
        onChange={(e) => setName(e.target.value)} // Updates state on typing
        style={{ padding: "10px", fontSize: "16px", width: "200px" }}
      />
      <p>Your name is: <strong>{name}</strong></p>
    </div>
  );
}

export default ComplexForm;
