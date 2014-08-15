<?php

/**
 * Class Shadow
 *
 * To trigger this in you tpl file just add the class: box-shadow.
 */
class Shadow {

  public function getForm($settings) {

    // Allow adding a shadow.
    $form['shadow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add a shadow?'),
      '#weight' => 1,
      '#default_value' => (isset($settings['shadow'])) ? $settings['shadow'] : 0,
    );

    // @todo Maybe add a default shadow here to call in the tpl.

    return $form;
  }
}
