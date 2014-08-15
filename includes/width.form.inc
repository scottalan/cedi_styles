<?php

class Width {

  public function getForm($settings, $fieldset = '') {

    // If using a fieldset.
    if (!empty($fieldset)) {

      // Form element for the width.
      $form[$fieldset]['width'] = array(
        '#type' => 'select',
        '#options' => $this->getOptions(),
        '#title' => t('Choose a width for the %target', array('%target' => $fieldset)),
        '#default_value' => ($settings[$fieldset]['width']) ? $settings[$fieldset]['width'] : '',
        '#weight' => 0,
      );

      // Form element for the custom target width.
      $form[$fieldset]['custom_' . $fieldset . '_width'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter an integer that will represent the width of the %target including the extension.', array('%target' => $fieldset)),
        '#description' => t('i.e., px, em, etc...'),
        '#default_value' => ($settings[$fieldset]['custom_' . $fieldset . '_width'] ? $settings[$fieldset]['custom_' . $fieldset . '_width'] : ''),
        '#weight' => $form[$fieldset]['width']['#weight'] + 1,
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-settings-' . $fieldset . '-width' => array('other')),
      );
    }
    // Do not include the $fieldset.
    else {

      // Form element for the width.
      $form['width'] = array(
        '#type' => 'select',
        '#options' => $this->getOptions(),
        '#title' => t('Choose a width for the element:'),
        '#default_value' => ($settings['width']) ? $settings['width'] : '1px',
        '#weight' => 0,
      );

      // Form element for the custom target width.
      $form['custom_' . $fieldset . '_width'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter an integer that will represent the width of the %target including the extension.', array('%target' => $fieldset)),
        '#description' => t('i.e., px, em, etc...'),
        '#default_value' => ($settings['custom_' . $fieldset . '_width'] ? $settings['custom_' . $fieldset . '_width'] : ''),
        '#weight' => $form[$fieldset]['width']['#weight'] + 1,
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array('edit-settings-width' => array('other')),
      );
    }
    return $form;
  }

  public function getOptions() {

    return drupal_map_assoc(
      array(
        t('1px'),
        t('2px'),
        t('3px'),
        t('4px'),
        t('5px'),
        t('other'),
      )
    );
  }

}
