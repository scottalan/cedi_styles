/**
 * Created by scott on 6/12/14.
 */

Drupal.behaviors.cediStyles = {
  attach: function (context, settings) {
    if (settings.hasOwnProperty('element')) {
      if (settings.element.hasOwnProperty('class')) {
        $(settings.element.class).each( function () {
          $(settings.element, context).once('cedi-style-class', function () {
            $(this).addClass(settings)
          });
        })
      }
      $(settings.element).each( function () {
        $(settings.element, context).once('cedi-style-class', function () {
          $(this).addClass(settings)
        });
      })
    }
  }
}
