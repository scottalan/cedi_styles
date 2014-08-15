<?php

class Colors {

  public function getForm($settings, $fieldset = '') {

    ctools_include('dependent');

    // If this is a fieldset build this form.
    if (!empty($fieldset)) {
      // Form element for color.
      $form[$fieldset]['color']  = array(
        '#type' => 'select',
        '#options' => $this->getOptions(),
        '#title' => t('Choose a color for the %target', array('%target' => $fieldset)),
        '#default_value' => ($settings[$fieldset]['color']) ? $settings[$fieldset]['color'] : 'lightgrey',
        '#weight' => 0,
      );
      // Form element for custom color.
      $form[$fieldset]['custom_color'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter a css color name or a #HexCode.'),
        '#default_value' => ($settings[$fieldset]['custom_color'] ? $settings[$fieldset]['custom_color'] : ''),
        '#weight' => $form[$fieldset]['color']['#weight'] + 1,
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-settings-' . $fieldset . '-color' => array('other')),
      );
    }
    // Otherwise build this form.
    else {
      // Form element for color.
      $form['color']  = array(
        '#type' => 'select',
        '#options' => $this->getOptions(),
        '#title' => t('Choose a color for the element:'),
        '#default_value' => ($settings['color']) ? $settings['color'] : 'lightgrey',
        '#weight' => 0,
      );
      // Form element for custom color.
      $form['custom_color'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter a css color name or a hex code without the # sign.'),
        '#default_value' => ($settings[$fieldset]['custom_color'] ? $settings[$fieldset]['custom_color'] : ''),
        '#weight' => $form[$fieldset]['color']['#weight'] + 1,
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-settings-color' => array('other')),
      );
    }
    return $form;
  }

  public function getOptions() {

    // Sets the colors.
    $lt_grey = '#F0F0F0';
    $white = '#FFFFFF';
    $black = '#222222';
    $orange = 'rgba(255, 102, 0, 1.0)';
    $blue = 'blue';
    $red = 'red';
    $yellow = 'yellow';
    $green = 'green';

    return array(
      $lt_grey => t('lightgrey'),
      $white => t('white'),
      $black => t('black'),
      $orange => t('orange'),
      $blue => t('blue'),
      $red => t('red'),
      $yellow => t('yellow'),
      $green => t('green'),
      'other' => t('other'),
    );
  }

}
