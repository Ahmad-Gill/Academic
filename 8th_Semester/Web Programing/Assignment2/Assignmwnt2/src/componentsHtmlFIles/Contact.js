import React, { useState, useEffect } from "react";
import Lottie from "react-lottie"; 
import "../componentCssFiles/contact.scss";

function Contact() {
  const [formData, setFormData] = useState({name: "",email: "",message: "",
  });

  const [successMessage, setSuccessMessage] = useState("");
  const [isSubmitting, setIsSubmitting] = useState(false); 
  const [animationData, setAnimationData] = useState(null);

  useEffect(() => {                   //Auto call 
    fetch(`${process.env.PUBLIC_URL}/Animation.json`)
      .then((response) => response.json())
      .then((data) => setAnimationData(data))
      .catch((error) => console.error("Error loading animation JSON:", error));
  }, []);

  const handleChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    setIsSubmitting(true);                 // Trigger animation on submit

    setTimeout(() => {
      console.log("Form Data Submitted:", formData);
      setSuccessMessage("Thank you! Your message has been sent.");
      setFormData({ name: "", email: "", message: "" });
      setIsSubmitting(false);
    }, 2000);
  };

  useEffect(() => {
    if (successMessage) {
      const timer = setTimeout(() => {
        setSuccessMessage("");
      }, 3000);
      return () => clearTimeout(timer);
    }
  }, [successMessage]);

  return (
    <div className="contactContainer">
      {/* Show animation overlay when submitting */}
      {isSubmitting && animationData && (
        <div className="animationOverlay">
          <Lottie options={{animationData: animationData,loop: true,autoplay: true,}} height={200}width={200}/>
        </div>
      )}

      <h2>Contact Me</h2>
      {successMessage && <p className="successMessage">{successMessage}</p>}
      <form onSubmit={handleSubmit}>
        <input type="text"name="name"placeholder="Your Name"value={formData.name}onChange={handleChange}required/>
        <input type="email"name="email"placeholder="Your Email"value={formData.email}onChange={handleChange}required/>
        <textarea name="message"placeholder="Your Message"value={formData.message}onChange={handleChange}required/>
        <button type="submit">{isSubmitting && animationData ? (
            <Lottie options={{animationData: animationData,loop: true,autoplay: true,}}height={50}width={50}/>) : (
            "Send Message"
          )}
        </button>
      </form>
    </div>
  );
}

export default Contact;
