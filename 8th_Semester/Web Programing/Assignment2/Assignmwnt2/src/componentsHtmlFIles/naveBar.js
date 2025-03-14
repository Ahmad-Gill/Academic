import React, { useState } from "react";
import "../componentCssFiles/naveBar.scss";
import { FaSearch, FaBars, FaTimes,FaSun, FaMoon } from "react-icons/fa";
import { Link } from "react-router-dom";

function NveBar() {
  const [search, setSearch] = useState("");
  const [menuOpen, setMenuOpen] = useState(false);
  const [darkMode, setDarkMode] = useState(false);

  const toggleBrightness = () => {
    setDarkMode(!darkMode);
    document.body.classList.toggle("dark-mode"); 
  };

  const handleType = (event) => {
    setSearch(event.target.value);
  };

  return (
    <div className="navBArMain">            
      <div className="logo">                      {/* Logo */}
        <img src="/favicon.ico" alt="Logo" />
      </div>
      <button className="hamburger" onClick={() => setMenuOpen(!menuOpen)}>  {/* Hamburger Menu Button */}
        {menuOpen ? <FaTimes /> : <FaBars />}
      </button>

      {/* Navigation Links */}
      <div className={`nav-links ${menuOpen ? "open" : ""}`}>
        <Link to="/" onClick={() => setMenuOpen(false)}>Home</Link>
        <Link to="/about" onClick={() => setMenuOpen(false)}>About</Link>
        <Link to="/DataEntry" onClick={() => setMenuOpen(false)}>DataEntry</Link>
        <Link to="/projects" onClick={() => setMenuOpen(false)}>Projects</Link>
        <Link to="/contact" onClick={() => setMenuOpen(false)}>Contact</Link>
      </div>

      {/* Search Bar */}
      <div className="search-container">
        <input
          className="NaveSearch"
          placeholder="Search"
          value={search}
          onChange={handleType}
        />
        <FaSearch className="search-icon" />
      </div>
      <button className="brightness-btn" onClick={toggleBrightness}>
        {darkMode ? <FaSun /> : <FaMoon />}
      </button>
    </div>
  );
}

export default NveBar;
