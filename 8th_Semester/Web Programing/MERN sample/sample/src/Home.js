import React from "react";
import { useState ,useEffect} from "react";

function Home({name="Unknown"}) {

  const [person, setNAme]=useState({"name":name,age:12})

useEffect(()=>{
setTimeout(()=>{

},2000
return ()=>{
  
}

)

},[])
  return (

    <div className="p-4">
      <h1 className="text-xl font-bold">Welcome to Our Website{person.name}{person.age}</h1>
      <p className="mt-2">This is the home page. Click on the links above to navigate.</p>
    </div>
  );
}

export default Home;
