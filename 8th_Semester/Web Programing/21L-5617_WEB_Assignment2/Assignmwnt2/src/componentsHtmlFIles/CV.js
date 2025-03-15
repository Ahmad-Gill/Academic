import React from "react";
import { useLocation } from "react-router-dom";
import "../componentCssFiles/CV.scss";

function CV() {
  const location = useLocation();
  const data = location.state;

  if (!data) {
    return <h1>No data received</h1>;
  }

  return (
    <div className="CV">
      <h1 className="HW_">CV Preview</h1>
      <div className="Personal">
      <img src={data.profileImage} alt="Profile" style={{ width: "150px", borderRadius: "50%" }} />
      <h1 className="HW name"> {data.name}</h1>
      </div>

      <div className="per">
        <h2 className="Hq">Personal INformation</h2>
        <div className="info-container">
  <div className="info-row">
    <p><strong>Age:</strong> {data.age}</p>
    <p><strong>Interests:</strong> {data.interests}</p>
    
  </div>
  <p className="bio"><strong>Bio:</strong> {data.bio}</p>
  <p className="bio"><strong>description:</strong> {data.description}</p>
</div>

<hr></hr>

      </div>
      <h2 className="Hq">Skills</h2>
      <div className="skills-container">
  {data.skills.split(",").map((skill, index) => (
    <p key={index}>#{skill.trim()}</p> 
  ))}
</div>


  
<hr />
<h2 className="Hq">Social Media</h2>
<div className="social-media-container">
  {data.socialMedia.map((item, index) => (
    <p key={index} className="social-item">
      <strong>#{item.name}:</strong> 
      <a href={item.url} target="_blank" rel="noopener noreferrer" className="social-url">{item.url}</a>
    </p>
  ))}
</div>


<hr />

<h2 className="Hq">Projects</h2>
<div className="projects-container">
  {data.projects.map((project, index) => (
    <div key={index} className="project-item">
      
      {/* Image and Title + Description on the same line */}
      <div className="project-header">
        {project.image && <img src={project.image} alt="Project" />}
        <div className="project-info">
          <p><strong>Title:</strong> {project.title}</p>
          <p><strong>Description:</strong> {project.description}</p>
        </div>
      </div>

      {/* GitHub link on a new line */}
      <p className="project-link">
        <strong>GitHub:</strong> 
        <a href={project.github} target="_blank" rel="noopener noreferrer"> {project.github}</a>
      </p>

      {/* Divider between projects */}
      {index !== data.projects.length - 1 && <hr className="project-divider" />}
      
    </div>
  ))}
</div>

    </div>
  );
}

export default CV;
