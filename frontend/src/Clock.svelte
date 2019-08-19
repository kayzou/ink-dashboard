<div class="clock">
    <h2>{hours}:{minutes}</h2>
    <h2>{weekday}, {day} {month}</h2>
</div>

<script>
	const weekdays = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
	const months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];

	export let hours, minutes, weekday, day, month;

	function time() {
	    const now = new Date();
        hours = ("0" + now.getHours()).slice(-2);
        minutes = ("0" + now.getMinutes()).slice(-2);
        weekday = weekdays[now.getDay()];
        day = now.getDate();
        month = months[now.getMonth()];
	}

	time();
	setInterval(time, 1000);

</script>

<style>
    .clock {
        display: flex;
        flex-direction: row;
        justify-content: space-between;
        margin-bottom: 32px;
    }

    h2 {
        font-size: 72px;
        line-height: 72px;
        margin-bottom: 24px;
        color: #575757;
    }
</style>
