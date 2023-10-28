const accordionItems = document.querySelectorAll('.accordion__item');

accordionItems.forEach((item) => {
  item.addEventListener('click', (e) => {
    openAccordion(e);
  });

  const openAccordion = (e) => {
    let target = e.currentTarget;

    if (!target.classList.contains('active')) {
      accordionItems.forEach((item) => {
        item.classList.remove('active');
      });
      target.classList.add('active');
    } else {
      target.classList.remove('active');
    }
  };
});
