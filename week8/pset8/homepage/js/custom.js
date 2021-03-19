document.addEventListener("DOMContentLoaded", function() {
    let course_button = document.querySelector("#button_cs50");
    course_button.addEventListener("click", function() {
        window.open("https://cs50.harvard.edu/x/2021/", '_blank');
    })

    let my_solutions_button = document.querySelector("#button_my_solutions");
    my_solutions_button.addEventListener("click", function() {
        window.open("https://github.com/chinhungtseng/cs50x2021", "_blank");
    })
});