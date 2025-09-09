#!/usr/bin/node
// 0-starwars_characters.js
// Prints all characters of a Star Wars movie in order

const request = require('request');

if (process.argv.length !== 3) {
  console.log('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

const fetchJSON = (url) =>
  new Promise((resolve, reject) => {
    request(url, { json: true }, (err, res, body) => {
      if (err) reject(err);
      else resolve(body);
    });
  });

(async () => {
  try {
    const film = await fetchJSON(url);
    const characters = film.characters;

    for (const charUrl of characters) {
      const character = await fetchJSON(charUrl);
      console.log(character.name);
    }
  } catch (error) {
    console.error(error);
  }
})();
