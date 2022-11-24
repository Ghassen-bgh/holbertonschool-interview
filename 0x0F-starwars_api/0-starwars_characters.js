#!/usr/bin/node
const request = require('request');
const id = process.argv[2];
request.get(`https://swapi-api.hbtn.io/api/films/${id}`, { json: true }, async(err, res, body) => {
    if (err) {
        return err;
    }
        const characters = body.characters;
        for (const character in characters) {
        await new Promise ((resolve, reject) => {
        request.get(characters[character], { json: true }, (err, res, body) => {
            if (err) {
            reject(err);
            } else {
            console.log(body.name);
            resolve();
        }
    });
  });
    }
});