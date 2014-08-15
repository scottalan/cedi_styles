<?php

class Border {

  public function getForm($settings) {

    ctools_include('dependent');

    $form['add_border'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add a border?'),
      '#default_value' => (isset($settings['add_border'])) ? $settings['add_border'] : 0,
      '#weight' => 2,
    );
    $form['border'] = array(
      '#type' => 'fieldset',
      '#title' => t('Border'),
      '#weight' => $form['add_border']['#weight'] + 1,
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('edit-settings-add-border' => array('1')),
    );

    $colors = new Colors();
    $border_colors = $colors->getForm($settings, 'border');
    $form = array_merge_recursive($form, $border_colors);

    $width = new Width();
    $border_width = $width->getForm($settings, 'border');
    $form = array_merge_recursive($form, $border_width);

    return $form;
  }

  public function getOptions() {

  }

}
