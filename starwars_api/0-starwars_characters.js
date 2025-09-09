#!/usr/bin/node
// 0-starwars_characters.js
// Prints all characters of a Star Wars movie

const request = require('request');

if (process.argv.length !== 3) {
  console.log('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, { json: true }, (err, res, body) => {
  if (err) {
    console.error(err);
    return;
  }

  if (!body.characters) {
    console.error('No characters found.');
    return;
  }

  const characters = body.characters;

  // Fetch each character name in order
  characters.forEach((charUrl) => {
    request(charUrl, { json: true }, (err, res, charBody) => {
      if (err) {
        console.error(err);
        return;
      }
      console.log(charBody.name);
    });
  });
});
