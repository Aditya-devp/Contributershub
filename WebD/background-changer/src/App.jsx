import { useState } from "react"

function App() {
  const [bg, setBg] = useState("white")
  return (
    <>
      <div className="w-full h-screen" style={{backgroundColor:bg}}>

      <div className="fixed flex flex-wrap justify-center bottom-12 inset-x-0 px-2">

        <div className="flex flex-wrap justify-center gap-3 shadow-xl bg-white px-3 py-2 rounded-full">
          <button onClick={() => setBg("red")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "red"}}>Red</button>
          <button onClick={() => setBg("yellow")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "yellow"}}>Yellow</button>
          <button onClick={() => setBg("pink")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "pink"}}>Pink</button>
          <button onClick={() => setBg("green")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "green"}}>Green</button>
          <button onClick={() => setBg("black")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "black"}}>Black</button>
          <button onClick={() => setBg("orange")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "orange"}}>Orange</button>
          <button onClick={() => setBg("olive")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "olive"}}>Olive</button>
          <button onClick={() => setBg("blue")} className="outline-none px-4 py-1 text-white rounded-full" style={{backgroundColor: "blue"}}>Blue</button>
        </div>

      </div>
      
      </div>
    </>
  )
}

export default App
