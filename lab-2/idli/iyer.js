const msg = new SpeechSynthesisUtterance();
let allVoices;

let voiceSelector = document.getElementById("voice-select");
let output = document.getElementById("output");
let speedMeter = document.getElementById("speed");

window.onload = () => {
  window.speechSynthesis.cancel();
};

voiceSelector.addEventListener("change", (e) => {
  if (allVoices.length > 0) {
    msg.voice = allVoices[parseInt(e.target.value)];
  }
});

speedMeter.addEventListener("change", (e) => {
  msg.rate = parseFloat(e.target.value);
});

window.speechSynthesis.onvoiceschanged = function () {
  allVoices = window.speechSynthesis.getVoices();
  allVoices.forEach((voice, ind) => {
    let opt = document.createElement("option");
    opt.value = ind;
    opt.text = voice.name;
    voiceSelector.appendChild(opt);
  });
  voiceSelector.value = 279;
  msg.voice = allVoices[279];
  msg.rate = 0.7;
  speedMeter.value = 0.7;
};

async function iyerify() {
  const textToIyerify = document.getElementById("text").value;
  if (textToIyerify === "") {
    msg.text = "aiyoo, timile haneko vayena!";
    window.speechSynthesis.speak(msg);
    return;
  }
  await idli(textToIyerify);
}

async function idli(string) {
  output.innerText = "";
  window.speechSynthesis.cancel();
  let splitted = string.split(" ");
  for (let i = splitted.length - 1; i >= 0; i--) {
    let str = [];
    for (let j = i; j <= splitted.length - 1; j++) {
      str.push(splitted[j]);
    }
    output.innerText += str.join(" ") + "\n";
    msg.text = str.join(" ");
    window.speechSynthesis.speak(msg);
    await new Promise((resolve) => {
      msg.onend = resolve;
    });
  }
}
