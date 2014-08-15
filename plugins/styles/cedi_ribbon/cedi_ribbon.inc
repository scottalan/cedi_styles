<?php
/**
 * @file
 * Definition of the bootstrap well pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Corner Ribbon'),
  'description' => t('Renders the pane with a text ribbon in the corner.'),
  'render pane' => 'cedi_ribbon_style_render_pane',
  'render region' => 'cedi_ribbon_style_render_region',
  'settings form' => 'cedi_ribbon_style_settings_form',
  'pane settings form' => 'cedi_ribbon_style_pane_settings_form',
  'panes' => TRUE,
  'regions' => TRUE,
  'hook theme' => array(
    'cedi_ribbon' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_ribbon',
      'template' => 'cedi-ribbon',
    ),
  ),
);


/**
 * Render callback for a single region.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_ribbon_style_render_region($vars) {
  $sep = '<div class="panel-separator"></div>';
  // add separator to end also because panels ipe js removes the last one
  $output = implode($sep, $vars['panes']) . $sep;

  // Then wrap it in a background color.
  return theme('cedi_ribbon', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Render callback for a single pane.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_ribbon_style_render_pane(&$vars) {
  $content = $vars['content'];
  $settings = $vars['settings'];

  if (empty($content->content)) {
    return;
  }

  // Add style css.
  drupal_add_css($vars['style']['path'] .  '/' . $vars['style']['name'] . '.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));

  // Theme the pane and add the ribbon.
  return theme('cedi_ribbon', array('content' => $output, 'settings' => $settings));
}

/**
 * Edit form callback.
 */
function cedi_ribbon_style_pane_settings_form($settings) {

  $form['ribbon'] = array(
    '#type' => 'checkbox',
    '#title' => t('Place a ribbon in the upper right corner?'),
    '#description' => t('Check this box to add a ribbon in the upper right corner of the pane.'),
    '#default_value' => ($settings['ribbon']) ? $settings['ribbon'] : FALSE,
  );

  $form['color'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(t('green'), t('red'), t('blue'))),
    '#title' => t('The color of the backgroud for this pane.'),
    '#description' => t('Enter a hex code for the color. %url', array('%url' => 'http://www.colorpicker.com/')),
    '#default_value' => (isset($settings['color']) ? $settings['color'] : ''),
  );

  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('The text to place on the ribbon.'),
    '#default_value' => (isset($settings['text']) ? $settings['text'] : ''),
  );

  return $form;
}

/**
 * Edit form callback.
 */
function cedi_ribbon_style_settings_form($settings) {

  return cedi_ribbon_style_pane_settings_form($settings);

}
