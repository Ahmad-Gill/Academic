import React from "react";
import { FaGithub, FaLinkedin, FaTwitter } from "react-icons/fa"; 
import "../componentCssFiles/footer.scss"; 

function Footer() {
  return (
    <footer className="footer">
      <div className="footerContainer">
        <p>© 2025 Muhammad Ahmad Gill. All Rights Reserved.</p>
        <div className="socialLinks">
          <a href="https://github.com/Ahmad-Gill/Ahmad-Gill" target="_blank" rel="noopener noreferrer">
            <FaGithub className="icon" /> GitHub
          </a>
          <a href="https://www.linkedin.com/in/muhammad-ahmad-gill-427772262/" target="_blank" rel="noopener noreferrer">
            <FaLinkedin className="icon" /> LinkedIn
          </a>
          <a href="#" target="_blank" rel="noopener noreferrer">
            <FaTwitter className="icon" /> Twitter
          </a>
        </div>
      </div>
    </footer>
  );
}

export default Footer;
