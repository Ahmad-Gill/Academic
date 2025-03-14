import React from "react";
import "../componentCssFiles/about.scss";

function About({ data }) {
  return (
    <div className="aboutContainer">
      <div className="textSection">
        <h1 className="mainHeading">👋 Hello, I AM {data.name}</h1>
        <p className="mainPara"><strong>Age:</strong> {data.age}</p>
        <p className="mainPara"><strong>Bio:</strong> {data.bio}</p>

        <p className="mainPara"><strong>Interests:</strong> {data.interests.join(", ")}</p>
        <p className="mainPara"><strong>Skills:</strong> {data.skills.join(", ")}</p>
      </div>

      <div className="imageSection">
        <img className="profileImage" src={data.image} alt="Profile" />
      </div>
    </div>
  );
}

export default About;
