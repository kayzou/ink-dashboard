import App from './App.svelte';
import Axios from 'axios';

export const WEATHER_API_KEY = '7a7a3963d44c16b10b8307ea90604300';
export const axios = Axios.create({});

export default new App({
	target: document.body,
	props: {}
});
