<?php
/**
 * @file
 * Definition of the cp balloon style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Overlay Text on an Element'),
  'description' => t('Renders text over another element (image).'),
  'render pane' => 'cedi_caption_overlay_style_render_pane',
  'settings form' => 'cedi_caption_overlay_style_settings_form',
  'pane settings form' => 'cedi_caption_overlay_style_pane_settings_form',
  'panes' => TRUE,
  'regions' => FALSE,
  'hook theme' => array(
    'cedi_caption_overlay' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_caption_overlay',
      'template' => 'cedi-caption-overlay',
    ),
  ),
);

/**
 * Render callback for a single pane.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_caption_overlay_style_render_pane(&$vars) {
  $content = $vars['content'];
  $settings = $vars['settings'];

  if (empty($content->content) || empty($content->title)) {
    return;
  }

  // Get the fields that could be involved here.
  $fields_instances = cedi_styles_panels_styles_get_fields($vars);

  foreach ($fields_instances as $field => $instance) {

  }

  $settings['title'] = $content->title;
  // Remove the title from the content so it doesn't show up as well.
  $content->title = '';

  // Add style css.
  drupal_add_css($vars['style']['path'] .  '/' . $vars['style']['name'] . '.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));

  // Theme the pane and add the ribbon.
  return theme('cedi_caption_overlay', array('content' => $output, 'settings' => $settings));
}

/**
 * Edit form callback.
 */
function cedi_caption_overlay_style_pane_settings_form($settings) {

  $form['color'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t('default'), t('primary'), t('success'), t('info'), t('warning'), t('danger'), t('link'))),
    '#title' => t('Choose a color for the button'),
    '#default_value' => ($settings['color']) ? $settings['color'] : FALSE,
  );

  return $form;
}

/**
 * Edit form callback.
 */
function cedi_caption_overlay_style_settings_form($settings) {

  //return $form;
}
