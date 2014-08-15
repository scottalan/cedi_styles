<?php
/**
 * @file
 * Definition of the cp balloon style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Link Button'),
  'description' => t('Renders the text as a button.'),
  'render pane' => 'cedi_link_button_style_render_pane',
  'settings form' => 'cedi_link_button_style_settings_form',
  'pane settings form' => 'cedi_link_button_style_pane_settings_form',
  'panes' => TRUE,
  'regions' => FALSE,
  'hook theme' => array(
    'cedi_link_button' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_link_button',
      'template' => 'cedi-link-button',
    ),
  ),
);

/**
 * Render callback for a single pane.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_link_button_style_render_pane(&$vars) {
  $content = $vars['content'];
  $settings = $vars['settings'];

  if ((empty($content->content) || empty($content->title)) && !isset($content->content['field_quick_links_links'])) {
    drupal_set_message('You must have a title when applying this style. Try again.', 'warning');
    return;
  }

  if (isset($content->content['field_quick_links_links'])) {
    foreach ($content->content['field_quick_links_links']['#items'] as $k => &$v) {
      $v['attributes']['class'] = 'btn' . ' ' . 'btn-' . $settings['size'] . ' ' . 'btn-' . $settings['color'];
      $settings['links'][] = $v;
      $content->content['field_quick_links_links'][$k]['#element'] = $v;
    }
//    $content->content['field_quick_links_links'][0]['#element']['attributes']['class'] = 'btn btn-' . $vars['settings']['color'];
//    $settings['link'] = $content->content['field_quick_links_links'];
    $settings['quick_links'] = TRUE;
  }
  elseif ($content->title) {
    $settings['title'] = $content->title;
    // Remove the title from the content so it doesn't show up as well.
    $content->title = '';
  }
  else {
    drupal_set_message('Applying style but could not find a link.', 'warning');
    return;
  }

  // Add style css.
  drupal_add_css($vars['style']['path'] .  '/' . $vars['style']['name'] . '.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));

  // Theme the pane and add the ribbon.
  return theme('cedi_link_button', array('content' => $output, 'settings' => $settings));
}

/**
 * Edit form callback.
 */
function cedi_link_button_style_pane_settings_form($settings) {

  $form['color'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t('default'), t('primary'), t('success'), t('info'), t('warning'), t('danger'), t('link'))),
    '#title' => t('Choose a color for the button'),
    '#default_value' => (isset($settings['color'])) ? $settings['color'] : 'primary',
  );
  $form['size'] = array(
    '#type' => 'select',
    '#options' => array(
      'xs' => t('X-Small'),
      'sm' => t('Small'),
      'default' => t('Default'),
      'lg' => t('Large'),
    ),
    '#title' => t('Size'),
    '#default_value' => (isset($settings['size'])) ? $settings['size'] : 'default',
  );
  $form['link_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to page.'),
    '#description' => t('If this button should link to a specific page enter the path here.'),
    '#default_value' =>(isset($settings['link_page'])) ? $settings['link_page'] : '',
  );
  $form['placement'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(t('left'), t('center'), t('right'))),
    '#title' => t('Alignment'),
    '#description' => t('Align left, center, right.'),
    '#default_value' =>(isset($settings['placement'])) ? $settings['placement'] : t('left'),
  );

  return $form;
}

/**
 * Edit form callback.
 */
function cedi_link_button_style_settings_form($form) {

  return $form;
}
