import './componentCssFiles/App.scss';
import{BrowserRouter, Routes,Route} from "react-router-dom"
import Home from './componentsHtmlFIles/home'
import DataEntry from './componentsHtmlFIles/DataEntry'
import NavBar from "./componentsHtmlFIles/naveBar"
import CV from "./componentsHtmlFIles/CV"
import About from "./componentsHtmlFIles/about"
import Footer from "./componentsHtmlFIles/Footer";
import Contact from "./componentsHtmlFIles/Contact";

function App() {
  const userData = {
    name: "Muhamad AHmad",
    age: 23,
    interests: ["Coding", "Gaming", "Reading","Sleeping"],
    skills: ["React", "JavaScript", "Python","C++"],
    image: "/me.jpg",
    bio: "A data scientist and developer with expertise in machine learning, web scraping, and automation. Passionate about AI, full-stack development, and optimizing business processes. Skilled in Python, React, and cloud technologies"
  };
  return (
   <BrowserRouter>
   <NavBar/>
   <Routes>
    <Route  path="/" element={<Home name="Muhammad Ahmad "  bio="A data scientist and developer with expertise in machine learning, web scraping, and automation. Passionate about AI, full-stack development, and optimizing business processes. Skilled in Python, React, and cloud technologies."/>} />
    <Route  path="/DataEntry" element={<DataEntry />} />
    <Route path="/cv" element={<CV />} />
    <Route path="/about" element={<About data={userData} />} />
    <Route path="/contact" element={<Contact />} />
   </Routes>
   <Footer />
   
   </BrowserRouter>
  );
}

export default App;
