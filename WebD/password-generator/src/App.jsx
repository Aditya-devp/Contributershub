import { useCallback, useEffect, useState, useRef } from "react"

function App() {
  const [length, setlength] = useState(8);
  const [numberAllowed, setNumber] = useState(false);
  const [charAllowed, setChar] = useState(false);
  const [password, setpassword] = useState("");
  // Ref hook
  const passwordRef = useRef(null)


  // Here we will use useCallback. It will allow us to cache a function between re-renders
  const passwordGenerator = useCallback(() => {
    let pass = "";
    let str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (numberAllowed) str += "0123456789";
    if (charAllowed) str += "`~!@#$%^&*()-_+:;/?";

    for(let i=1; i<=length; i++) {
      let char = Math.floor(Math.random() * str.length + 1);
      pass += str.charAt(char);
    }

    setpassword(pass);
  }, [length, numberAllowed, charAllowed, setpassword
  ]);

  const copyPassword = useCallback(() => {
    passwordRef.current?.select();
    window.navigator.clipboard.writeText(password)
  }, [password])

  useEffect(() => {
    passwordGenerator()}, [length, numberAllowed,charAllowed, passwordGenerator])
  
  return (
    <>
      <div className="w-full max-w-md mx-auto shadow-md rounded-lg px-4 my-8 text-orange-500 bg-gray-600">
      <h1 className="text-white text-center my-3">Password Generator</h1>

      <div className="flex shadow rounded-lg overflow-hidden mb-4">
        <input 
        type="text"
        value={password}
        className="outline-none w-full py-1 px-3"
        placeholder="password"
        readOnly
        ref={passwordRef}
        />
        <button onClick={copyPassword} className="outline-none bg-red-800 text-white px-3 py-0.5 shrink-0">Copy</button>
      </div>

      <div className="flext text-sm gap-x-2">
        <div className="flex items-center gap-x-1">
          <input
          type="range"
          min={6}
          max={100}
          value={length}
          className="cursor-pointer"
          onChange = {(e) => {setlength(e.target.value)}}
          />
          <label> Length: {length} </label>
        </div>
        <div className="flex items-center gap-x-1">
          <input
          type="checkbox"
          defaultChecked={numberAllowed}
          id="numberInput"
          onChange = {() => {setNumber((prev) => !prev)}}
          />
          <label htmlFor="numberInput">Numbers</label>
        </div>
        <div className="flex items-center gap-x-1">
          <input
          type="checkbox"
          defaultChecked={charAllowed}
          id="charInput"
          onChange = {() => {setChar((prev) => !prev)}}
          />
          <label htmlFor="charInput">Characters</label>
        </div>
      </div>
      </div>
    </>
  )
}

export default App
