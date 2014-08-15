<?php
/**
 * @file
 * Definition of the bootstrap well pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Cedi Box'),
  'description' => t('Renders the pane in a box.'),
  'render pane' => 'cedi_box_style_render_pane',
  'render region' => 'cedi_box_style_render_region',
  'pane settings form' => 'cedi_box_style_settings_form',
  'hook theme' => array(
    'cedi_box' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_box',
      'template' => 'cedi-box',
    ),
  ),
);


/**
 * Render callback for a single region.
 */
function theme_cedi_box_style_render_region($vars) {
  $sep = '<div class="panel-separator"></div>';
  // add separator to end also because panels ipe js removes the last one
  $output = implode($sep, $vars['panes']) . $sep;

  // Then wrap it in a well
  return theme('cedi_box', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Render callback for a single pane.
 */
function theme_cedi_box_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  if (empty($content->content)) {
    return;
  }

  // Add style css.
  drupal_add_css($vars['style']['path'] .  '/' . $vars['style']['name'] . '.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));

  $vars['settings']['extra_class'] = 'inner-pane';

  // Then wrap it in a well
  return theme('cedi_box', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Settings form callback.
 */
function cedi_box_style_settings_form($style_settings) {

  //return $form;
}
