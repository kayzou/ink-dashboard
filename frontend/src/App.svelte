<div class="app">
    <Clock class="clock"></Clock>
    <Weather class="weather"></Weather>
</div>

<script>
    import Weather from "./Weather.svelte"
    import Clock from "./Clock.svelte"
</script>

<style>
    .app {
        padding: 64px 80px;
    }

    .top {
        display: flex;
        justify-content: space-between;
    }
</style>
