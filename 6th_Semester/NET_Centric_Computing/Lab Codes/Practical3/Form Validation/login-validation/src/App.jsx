import { useState } from 'react';

function App() {
  const [name, setName] = useState('')
  const [password, setPassword] = useState('')
  const [errors, setErrors] = useState({
    name: '',
    password: ''
  })

  const handleSubmit = ((e) => {
    e.preventDefault(); // Prevents the default action of the form which is to reload the page

    let formErrors = {};

    if (!name) {
      formErrors.name = "Name is required";
      setErrors(formErrors);
      return false; // Return false to stop the execution of the function
    }

    if (!password) {
      formErrors.password = "Password is required";
      setErrors(formErrors);
      return false;
    }

    if (Object.keys(formErrors).length === 0) {
      alert('Form submitted successfully');
      return;
    }
  })

  return (
    <form onSubmit={handleSubmit}>
      {/* Name field */}
      <label htmlFor="name">Name:</label>
      <input
        type='text'
        value={name}
        onChange={(e) => setName(e.target.value)}
      />
      <br />
      {errors.name && <p>{errors.name}</p>}
      <br />

      {/* Password field */}
      <label htmlFor='password'>Password: </label>
      <input
        type='text'
        value={password}
        onChange={(e) => setPassword(e.target.value)}
      />
      <br />
      {errors.password && <p>{errors.password}</p>}
      <br />

      {/* Submit button */}
      <button
        type='submit'
      >Submit</button>
    </form>
  )
}

export default App
