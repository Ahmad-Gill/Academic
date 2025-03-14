import { Link } from "react-router-dom";
import React from "react";

function Navbar() {
  return (
    <nav className="p-4 bg-gray-800 text-white flex justify-between">
      <h1 className="text-lg font-bold">My Website</h1>
      <div>
        <Link to="/" className="mr-4">Home</Link>
        &nbsp;
        <Link to="/about" className="mr-4">About</Link>
        &nbsp;
        <Link to="/contact" className="mr-4">Contact Us</Link>
      </div>
    </nav>
  );
}

export default Navbar;
