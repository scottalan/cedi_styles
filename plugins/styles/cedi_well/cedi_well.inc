<?php
/**
 * @file
 * Definition of the bootstrap well pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Background Color'),
  'description' => t('Renders the panes within a background color'),
  'render region' => 'cedi_well_style_render_region',
  'render pane' => 'cedi_well_style_render_pane',
  'pane settings form' => 'cedi_well_style_settings_form',
  'settings form' => 'cedi_well_style_settings_form',
  'panes' => TRUE,
  'regions' => TRUE,
  'hook theme' => array(
    'cedi_well' => array(
      'variables' => array('title' => '', 'content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_well',
      'template' => 'cedi-well',
    ),
  ),
);


/**
 * Render callback for a single region.
 */
function theme_cedi_well_style_render_region($vars) {
  // Add style css.
  // @todo Change this to match the naming convention.
  drupal_add_css($vars['style']['path'] .  '/cedi-well.css');

  // Add separator to end also because panels ipe js removes the last one.
  $output = cedi_styles_add_separator($vars);

  // Then wrap it in a well
  return theme('cedi_well', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Render callback for a single pane.
 */
function theme_cedi_well_style_render_pane($vars) {
  $title = $vars['content']->title;
  $vars['content']->title = '';
  $content = $vars['content'];

  if (empty($content->content)) {
    return;
  }

  // Add style css.
  // @todo Change this to match the naming convention.
  drupal_add_css($vars['style']['path'] .  '/cedi-well.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));

  // Then wrap it in a well
  return theme('cedi_well', array('title' => $title, 'content' => $output, 'settings' => $vars['settings']));
}

/**
 * Settings form callback.
 */
function cedi_well_style_settings_form($settings) {
  // Set variable for colorizer stylesheet.
//  cedi_styles_colorizer_set_stylesheet_path('cedi_well');

  $form['well'] = array(
    '#type' => 'fieldset',
    '#title' => 'Background Settings',
    '#weight' => 0,
  );
  $form['well']['well_modifier'] = array(
    '#type' => 'select',
    '#title' => t('Well modifier'),
    '#options' => array(
      'cedi-well-sm' => t('Small'),
      'cedi-well-md' => t('Medium'),
      'cedi-well-lg' => t('Large'),
      '' => t('Normal'),
    ),
    '#default_value' => (isset($settings['well']['well_modifier'])) ? $settings['well']['well_modifier'] : '',
    '#description' => t('Controls the rounded corners on the well.'),
  );
  $form['well']['include_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include the title?'),
  );

  // Add the plugin files.
//  cedi_styles_include_plugins();

  // Add color forms.
  $colors = new Colors();
  $colorform = $colors->getForm($settings, 'well');
  $form = array_merge_recursive($form, $colorform);

  // Add shadow forms.
  $shadow = new Shadow();
  $shadowform = $shadow->getForm($settings, 'well');
  $form = array_merge_recursive($form, $shadowform);

  // Add border forms.
  $border = new Border();
  $borderform = $border->getForm($settings);
  $form = array_merge_recursive($form, $borderform);

  // So js knows what element we want to target.
  $settings['element']['class'] = 'well';

  // Test adding colorizer.
//  $form += colorizer_admin_form(FALSE, 'plugin');

  return $form;
}
