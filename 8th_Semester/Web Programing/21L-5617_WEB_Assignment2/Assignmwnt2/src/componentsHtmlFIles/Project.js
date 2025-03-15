import React, { useState, useEffect } from "react";
import "../componentCssFiles/project.scss";

const Projects = ({ projects = [] }) => {
  const [allProjects, setAllProjects] = useState(projects);    // store projects taht is pass from asa param

  useEffect(() => {
    const fetchProjects = async () => {
      try {
        const response = await fetch("https://gist.githubusercontent.com/Ahmad-Gill/50d2b4465e139bf6957aa80a12058348/raw/492cde1519c908dbe1f99037a91dc7e3790d36cf/gistfile1.txt");
        if (!response.ok) {
          throw new Error(`Failed to fetch projects: ${response.statusText}`);
        }
        const textData = await response.text();   //the defoult store is as a text 
        const jsonData = JSON.parse(textData);
        setAllProjects([...projects, ...jsonData]);     // combine fectch data and param data in one array the drag and drop is easy 
      } catch (err) {
        console.error("Fetching error:", err);
      }
    };

    fetchProjects();
  }, [projects]);

                       
  const handleDragStart = (e, index) => {     //When a user starts dragging an item, this function stores its index in
    e.dataTransfer.setData("index", index);
  };

  const handleDrop = (e, dropIndex) => {
    e.preventDefault();
    const dragIndex = e.dataTransfer.getData("index"); // get the dragitem index 

    let updatedProjects = [...allProjects];
    const draggedItem = updatedProjects.splice(dragIndex, 1)[0]; 
    updatedProjects.splice(dropIndex, 0, draggedItem);
    setAllProjects(updatedProjects);
  };

  const allowDrop = (e) => {
    e.preventDefault();
  };

  return (
    <div className="projects-container">
      <h1 className="title">Project Display</h1>

      {allProjects.length === 0 ? (
        <p className="loading-message">Loading projects...</p>
      ) : (
        <div className="project-grid">
          {allProjects.map((project, index) => (
            <div key={index} className="project-card" draggable onDragStart={(e) => handleDragStart(e, index)} onDragOver={allowDrop} onDrop={(e) => handleDrop(e, index)}>
              <img src={project.image} alt={project.title}className="project-image"/>
              <h2 className="project-title">{project.title}</h2>
              <p className="project-description">{project.description}</p>
              <a href={project.github}target="_blank"rel="noopener noreferrer"className="project-link">View on GitHub</a>
            </div>
          ))}
        </div>
      )}
    </div>
  );
};

export default Projects;
