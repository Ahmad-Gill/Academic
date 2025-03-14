import React from "react";
import { Link } from "react-router-dom";
import "../componentCssFiles/home.scss";

function Home(props) {
  return (
    <div className="homeContainer">
      <div className="textSection">
        <h1 className="mainHeading">👋 Hello, I AM {props.name}</h1>
        <p className="mainPara">{props.bio}</p>

        <div className="homeLinks">
          <Link to="/projects">MY Projects</Link>
          <Link to="/contact">Contact ME</Link>
        </div>
      </div>

      <div className="imageSection">
        <img className="profileImage" src={`${process.env.PUBLIC_URL}/me.jpg`} alt="Profile" />
      </div>
    </div>
  );
}

export default Home;
