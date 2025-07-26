const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');

const app = express();
app.use(bodyParser.json());

const DATA_DIR = path.join(__dirname, 'data');
if (!fs.existsSync(DATA_DIR)) fs.mkdirSync(DATA_DIR);

function load(type) {
  const file = path.join(DATA_DIR, type + '.json');
  if (!fs.existsSync(file)) fs.writeFileSync(file, '[]');
  return JSON.parse(fs.readFileSync(file));
}
function save(type, arr) {
  fs.writeFileSync(
    path.join(DATA_DIR, type + '.json'),
    JSON.stringify(arr, null, 2)
  );
}

['reports','resources','requests','announcements'].forEach(type => {
  app.get(`/api/${type}`, (req, res) => {
    res.json(load(type));
  });
  app.post(`/api/${type}`, (req, res) => {
    const arr = load(type);
    if (type === 'announcements' && arr.length >= 5) {
      return res.status(400).json({ error: 'Max 5 announcements allowed' });
    }
    arr.push(req.body);
    save(type, arr);
    res.json({ success: true });
  });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, '0.0.0.0', () => 
  console.log(`Broker listening on port ${PORT} (0.0.0.0)`)
);
