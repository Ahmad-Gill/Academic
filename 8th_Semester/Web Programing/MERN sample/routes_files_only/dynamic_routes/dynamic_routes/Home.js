import { Link } from "react-router-dom";
import React from "react";
import books from "./books"; // Import books


function Home() {
  return (
    <div className="p-4">
      <h1 className="text-xl font-bold">Book Store</h1>
      <ul className="mt-4">
        {books.map((book) => (
          <li key={book.id} className="mt-2">
            <Link to={`/book/${book.id}`} className="text-blue-500">
              {book.title}
            </Link>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default Home;