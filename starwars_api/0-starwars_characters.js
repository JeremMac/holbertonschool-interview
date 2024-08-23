#!/usr/bin/node
import requests
import sys

def get_star_wars_characters(movie_id):
    url = f"https://swapi.dev/api/films/{movie_id}/"
    
    response = requests.get(url)
    
    if response.status_code != 200:
        print(f"Erreur: impossible de récupérer les données pour le film ID {movie_id}")
        return
    

    film_data = response.json()
    
    characters = film_data.get("characters", [])
    
    for character_url in characters:
        character_response = requests.get(character_url)
        character_data = character_response.json()
        print(character_data.get("name"))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ./0-starwars_characters.py <Movie ID>")
    else:
        movie_id = sys.argv[1]
        get_star_wars_characters(movie_id)
