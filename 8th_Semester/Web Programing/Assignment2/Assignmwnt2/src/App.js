import './componentCssFiles/App.scss';
import{BrowserRouter, Routes,Route} from "react-router-dom"
import Home from './componentsHtmlFIles/home'
import DataEntry from './componentsHtmlFIles/DataEntry'
import NavBar from "./componentsHtmlFIles/naveBar"
import CV from "./componentsHtmlFIles/CV"
import About from "./componentsHtmlFIles/about"
import Footer from "./componentsHtmlFIles/Footer";
import Contact from "./componentsHtmlFIles/Contact";
import Project from "./componentsHtmlFIles/Project";

function App() {
  const userData = {
    name: "Muhammad Ahmad",
    age: 23,
    interests: ["Coding", "Gaming", "Reading", "Sleeping"],
    skills: ["React", "JavaScript", "Python", "C++"],
    image: "/me.jpg",
    bio: "A data scientist and developer with expertise in machine learning, web scraping, and automation. Passionate about AI, full-stack development, and optimizing business processes. Skilled in Python, React, and cloud technologies."
  };

  const projects =  [
    {
      title: "Para 1 - John's Portfolio",
      description: "A personal portfolio built with React and Tailwind CSS.",
      image:
        "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR7hQFIOwguGVvfKCi6DC7Cbsr6YIDnRKueBw&s",
      github: "https://github.com/Ahmad-Gill/Ahmad-Gill",
    },
    {
      title: "Para 2 - Sophie's E-commerce Store",
      description: "An e-commerce platform with Stripe integration.",
      image:
        "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTKCVJ38BPy1if0MeOIy1iDL2neB_jeHnPqUw&s",
      github: "https://github.com/Ahmad-Gill/Ahmad-Gill",
    },
    {
      title: "Para 3 - Michael's Task Manager",
      description:
        "A Kanban-style task manager with drag-and-drop functionality.",
      image:
        "https://i.ytimg.com/vi/utyYSamLd5g/hq720.jpg?sqp=-oaymwEhCK4FEIIDSFryq4qpAxMIARUAAAAAGAElAADIQj0AgKJD&rs=AOn4CLDH2xY6GecCmI9uDjEfbztpXHZTOw",
      github: "https://github.com/Ahmad-Gill/Ahmad-Gill",
    },
    {
      title: "Para 4 - Emily's Chat App",
      description:
        "A real-time chat application using WebSockets and Firebase.",
      image:
        "https://media.licdn.com/dms/image/v2/D4D12AQF4wPzUFfzVlQ/article-cover_image-shrink_600_2000/article-cover_image-shrink_600_2000/0/1715864980954?e=2147483647&v=beta&t=pluYvAbrpRkERj5vxkmHH2cwRpyaV1_nLlXTQplmaHw",
      github: "https://github.com/Ahmad-Gill/Ahmad-Gill",
    },
    {
      title: "Para 5 - David's Blog Platform",
      description: "A full-stack blog application with Markdown support.",
      image:
        "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTnDI63gtnlRfMXh9UP4U1jTrgIxlmqsP4FIg&s",
      github: "https://github.com/Ahmad-Gill/Ahmad-Gill",
    },
];

  return (
    <BrowserRouter>
      <NavBar />
      <Routes>
        <Route path="/" element={ <Home name="Muhammad Ahmad" bio="A data scientist and developer with expertise in machine learning, web scraping, and automation. Passionate about AI, full-stack development, and optimizing business processes. Skilled in Python, React, and cloud technologies."/>} />
        <Route path="/DataEntry" element={<DataEntry />} />
        <Route path="/cv" element={<CV />} />
        <Route path="/about" element={<About data={userData} />} />
        <Route path="/contact" element={<Contact />} />
        <Route path="/project" element={<Project projects={projects} />} />
      </Routes>
      <Footer />
    </BrowserRouter>
  );
}

export default App;