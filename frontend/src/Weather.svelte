<div class="weather">
    <div class="top">
        <img class="image" src="icons/weather-clear-night-icon.png">
        <h1>{weather.temperature.now}°</h1>
    </div>
    <div class="bottom">
        <h2>{weather.condition}</h2>
        <h3>{weather.rain}%</h3>
    </div>
</div>

<script>
    //import { onMount } from "svelte";
    //import {axios, WEATHER_API_KEY} from "./main";

	export let weather = {
        city: 'Winterthur',
        humidity: 60,
        condition: 'Mostly clear',
        rain: 60,
        temperature: {
            now: 25,
            high: 32,
            low: 17,
        },
	};

	/*onMount(async () => {
        const {data} = await axios.get(`https://api.openweathermap.org/data/2.5/weather?units=metric&id=2657970&appid=${WEATHER_API_KEY}`);
        weather = {
            ...weather,
            city: data.name,
            humidity: data.main.humidity,
            condition: data.weather.description,
            temperature: {
                now: data.main.temp,
                high: data.main.temp_max,
                low: data.main.temp_min,
            },

        }
	});*/

</script>

<style>
    .weather {
        display: flex;
        justify-content: space-between;
    }

    .top {
        display: flex;
    }

    .bottom {
        text-align: right;
    }

     img {
            height: 180px;
     }

    h1 {
        font-size: 180px;
        line-height: 180px;
    }

    h2 {
        font-size: 64px;
    }

    h3 {
        font-size: 48px;
    }
</style>
