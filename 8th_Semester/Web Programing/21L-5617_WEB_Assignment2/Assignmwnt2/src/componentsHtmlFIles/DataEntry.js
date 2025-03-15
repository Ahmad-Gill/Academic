import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import "../componentCssFiles/DataEntry.scss";

function DataEntry() {
  const navigate = useNavigate();     {/* ---------------------------------USe to send Data to nedt CV PAge'*/}
  

  {/* ---------------------------------Initailize all the required fields*/}
  const [profileImage, setProfileImage] = useState("/profile.png");
  const [name, setName] = useState("");
  const [age, setAge] = useState("");
  const [bio, setBio] = useState("");
  const [interests, setInterests] = useState("");
  const [skills, setSkills] = useState("");
  const [description, setDescription] = useState("");
  const [socialMedia, setSocialMedia] = useState([{ name: "", url: "" }]);
  const [projects, setProjects] = useState([
    { title: "", description: "", image: null, github: "" },
  ]);


    {/* ---------------------------------Set Image of a person */}
  const handleImageChange = (event, setImage) => {
    const file = event.target.files[0];
    if (file) {
      setImage(URL.createObjectURL(file)); 
    }
  };


  {/* ---------------------------------Add new Social Media link and name  */}
  const handleSocialMediaChange = (index, field, value) => {
    const updatedSocialMedia = [...socialMedia];
    updatedSocialMedia[index][field] = value;
    setSocialMedia(updatedSocialMedia);
  };
  {/* --------------------------------on press buttion add a new input and clear the input  */}
  const addSocialMedia = () => {
    setSocialMedia([...socialMedia, { name: "", url: "" }]);
  };


  {/* --------------------------------Add new Project values*/}
  const handleProjectChange = (index, field, value) => {
    const updatedProjects = [...projects];
    updatedProjects[index][field] = value;
    setProjects(updatedProjects);
  };

   {/* --------------------------------Save the image of Every PRoject*/}
  const handleProjectImageChange = (index, event) => {
    const file = event.target.files[0];
    if (file) {
      const updatedProjects = [...projects];
      updatedProjects[index].image = URL.createObjectURL(file);
      setProjects(updatedProjects);
    }
  };
{/* --------------------------------on press buttion add a new input and clear the input  */}
  const addProject = () => {
    setProjects([...projects, { title: "", description: "", image: null, github: "" }]);
  };


  {/* --------------------------------Main Submission  */}
  const handleSubmit = () => {
    if (!name || !age || !bio || !interests || !skills || !description) {      {/* --------------------------------ALL required Checks  */}
      alert("Please fill in all required fields.");
      return;
    }
    
    const formData = {
      profileImage,
      name,
      age,
      bio,
      interests,
      skills,
      description,
      socialMedia: socialMedia.filter(item => item.name && item.url),
      projects: projects.filter(item => item.title && item.description && item.github), 
    };
  
    navigate("/cv", { state: formData });           {/* --------------------------------Send All Data to CV Page   */}
  };

  return (
    <div className="DataEntryMain">

      <form onSubmit={(e) => e.preventDefault()}>

        <h1>Personal Information</h1>
        <div className="PersonalInformation">
          <div className="Image">          {/* Profile Picture Upload */}
          {profileImage && <img src={profileImage} alt="Profile Preview" className="profile-preview" />}
  <input type="file"  accept="image/*" onChange={(e) => handleImageChange(e, setProfileImage)} className="file-input"/>    
   <br />
   </div>

<div className="nameAge">
          <label>Name:</label>
          <input type="text" value={name} onChange={(e) => setName(e.target.value)} required placeholder="Student Name"/>
          <br />

          <label>Age:</label>
          <input type="number" value={age} onChange={(e) => setAge(e.target.value)} required placeholder="Age" />
  <br />
          </div>
          <div className="nameAge">
          <label>Bio:</label>
          <input type="text" value={bio} onChange={(e) => setBio(e.target.value)} required placeholder="BIO"/>
          <br />

          <label>Interests:</label>
          <input type="text" value={interests} onChange={(e) => setInterests(e.target.value)} required placeholder="Interests" />
          <br />
          </div>
          <div className="nameAge">
          <label>Skills:</label>
          <input type="text" value={skills} onChange={(e) => setSkills(e.target.value)} required placeholder="Skill1,skill2" />
          <br />

          <label>Description:</label>
          <input type="text" value={description} onChange={(e) => setDescription(e.target.value)} required  placeholder="Description"/>
          <br />
        </div>
        </div>
<hr />
        <h2>Projects</h2>

        {projects.map((project, index) => (
           <div className="project">
                     <div key={index} className="project-entry">
            <label>Project Title:</label>
            <input
              type="text" value={project.title} onChange={(e) => handleProjectChange(index, "title", e.target.value)} required placeholder="Title"
            />
            <br />
            <label>Project Description:</label>
            <input type="text" value={project.description} onChange={(e) => handleProjectChange(index, "description", e.target.value)} required placeholder="Description"
            />
            <br />
</div><br />
<div className="Image">
    {project.image && <img src={project.image} alt="Project Preview" className="profile-preview" />}
    <input type="file" accept="image/*" onChange={(e) => handleProjectImageChange(index, e)} className="file-input"
    />
    <br />
    <label>GitHub Link:</label>
    <input type="url" value={project.github}onChange={(e) => handleProjectChange(index, "github", e.target.value)}required className="file-input"  placeholder="LINK"// Same class for consistency
    />
    <br />
  </div>
          </div>
        ))}
        <button type="button" onClick={addProject}>Add Another Project</button>
<hr></hr>
        <h2>Social Media Links</h2>
        {socialMedia.map((social, index) => (
          <div className="link">
          <div key={index} className="social-media-entry">
            <label>Social Media Name:</label>
            <input type="text" value={social.name} onChange={(e) => handleSocialMediaChange(index, "name", e.target.value)} required placeholder="Name"
            />
            <br />

            <label>Social Media URL:</label>
            <input type="url" value={social.url} onChange={(e) => handleSocialMediaChange(index, "url", e.target.value)} required placeholder="URL"
            />
            <br />
          </div>
          </div>
        ))}
        <button type="button" onClick={addSocialMedia}>Add Social Media</button>


        <br />
        <br />
        <button type="button" onClick={handleSubmit}>Submit</button>
      </form>
    </div>
  );
}

export default DataEntry;
