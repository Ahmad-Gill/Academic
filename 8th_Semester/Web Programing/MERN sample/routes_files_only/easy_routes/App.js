import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import React from "react";
import "./index.css";
import Navbar from "./Navbar";
import Home from "./Home";
import About from "./About";
import Contact from "./Contact";

function App() {
  return (
    <Router>
      <Navbar />
      <Routes>
        <Route path="/" element={<Home />} />  {/* Default page */}
        <Route path="/about" element={<About />} />
        <Route path="/contact" element={<Contact />} />
      </Routes>
      {/* Define Footer Here */}
    </Router>
  );
}

export default App;
