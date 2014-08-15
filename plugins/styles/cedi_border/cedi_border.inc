<?php
/**
 * @file
 * Definition of the cp balloon style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Border'),
  'description' => t('Adds a border to a pane or region'),
  'render pane' => 'cedi_border_style_render_pane',
  'render region' => 'cedi_border_style_render_region',
  'pane settings form' => 'cedi_border_style_settings_form',
  'settings form' => 'cedi_border_style_settings_form',
  'panes' => TRUE,
  'regions' => TRUE,
  'hook theme' => array(
    'cedi_border' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_border',
      'template' => 'cedi-border',
    ),
  ),
);

/**
 * Options for the border color.
 */
function cedi_border_get_color_options() {
  return drupal_map_assoc(
    array(
      t('black'),
      t('lightgrey'),
      t('orange'),
      t('blue'),
      t('red'),
      t('yellow'),
      t('green'),
      t('other'),
    )
  );
}

/**
 * Options for the border width.
 */
function cedi_border_get_width_options() {
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

/**
 * Render callback for a single region.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_border_style_render_region($vars) {
//  $sep = '<div class="panel-separator"></div>';
//  // add separator to end also because panels ipe js removes the last one
//  $output = implode($sep, $vars['panes']) . $sep;

  // Then wrap it in a background color.
  return theme('cedi_border', array('content' => $vars['panes'], 'settings' => $vars['settings'], 'color' => $vars['color'], 'border' => $vars['border']));
}

/**
 * Render callback for a single pane.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_border_style_render_pane(&$vars) {
  $content = $vars['content'];

  $fields_instances = cedi_cp_panels_styles_get_fields($vars);

  foreach ($fields_instances as $field => $instance) {

  }

  // Add style css.
  drupal_add_css($vars['style']['path'] .  '/' . $vars['style']['name'] . '.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));

  //$vars['settings']['extra_class'] = 'inner-pane';

  // Theme the pane and add the border.
  return theme('cedi_border', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Edit form callback.
 */
function cedi_border_style_pane_settings_form($settings) {

  $form = array();

  $border = new Border();
  $borderform = $border->getForm($settings);
  $form = array_merge_recursive($form, $borderform);

  return $form;
}

/**
 * Edit form callback.
 */
function cedi_border_style_settings_form($settings) {

  //return $form;
  $form = array();

  $border = new Border();
  $borderform = $border->getForm($settings);
  $form = array_merge_recursive($form, $borderform);

  return $form;
}
