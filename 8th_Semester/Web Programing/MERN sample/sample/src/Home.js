import React from "react";

function Home({name="Unknown"}) {
  return (
    <div className="p-4">
      <h1 className="text-xl font-bold">Welcome to Our Website{name}</h1>
      <p className="mt-2">This is the home page. Click on the links above to navigate.</p>
    </div>
  );
}

export default Home;
