import { useParams, Link } from "react-router-dom";
import React from "react";
import books from "./books"; // Import books

function BookDetail() {
  const { id } = useParams();
  const book = books.find((b) => b.id === parseInt(id));

  return book ? (
    <div className="p-4">
      <h2 className="text-lg font-bold">{book.title}</h2>
      <p className="mt-2">Author: {book.author}</p>
      <Link to="/" className="text-blue-500 mt-4 block">
        Back to Home
      </Link>
    </div>
  ) : (
    <p className="p-4 text-red-500">Book not found!</p>
  );
}

export default BookDetail;
