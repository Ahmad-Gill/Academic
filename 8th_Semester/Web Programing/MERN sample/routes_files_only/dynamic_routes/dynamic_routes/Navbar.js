// Navbar.js
import { Link } from "react-router-dom";
import React from "react";

function Navbar() {
  return (
    <nav className="p-4 bg-gray-800 text-white flex justify-between">
      <h1 className="text-lg font-bold">Book Store</h1>
      <div>
        <Link to="/" className="mr-4">Home</Link>
      </div>
    </nav>
  );
}

export default Navbar;